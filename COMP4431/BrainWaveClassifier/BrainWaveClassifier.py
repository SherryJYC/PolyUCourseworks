import numpy as np
from scipy.io import loadmat
from sklearn.svm import SVC
from sklearn.utils import shuffle
from sklearn.decomposition import PCA 
from sklearn.pipeline import Pipeline
import matplotlib.pyplot as plt
import sklearn.preprocessing as pre
from sklearn.preprocessing import StandardScaler, Normalizer, RobustScaler
from sklearn.ensemble import RandomForestClassifier, VotingClassifier, GradientBoostingClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.decomposition import FastICA

def circSlice(a, start, length):
    return (a * 2)[start:start+length]

def channelWeight(i):
    fac = [1.8, 1.8, 2, 1.8]
    return fac[i]

channel2 = [a - 1 for a in[51, 52, 53, 57, 58, 59, 60, 61, 63, 64, 65, 66, 67, 69, 70, 71, 72, 74, 77, 78, 79, 84, 85, 86, 87, 89, 90, 91, 92, 93, 95, 96, 97, 98, 100, 101]]
channel = []
channel.append(channel2)

instance = []
label = []

mat = [
        '../data/train_1_LiuZiAng_20161107_064135_fil_seg_bcr',
    '../data/train_1_ZhengHongYi_20161124_013427_fil_seg_bcr',
    '../data/train_3_ChenHaiYu_20161107_081817_fil_seg_bcr',
    '../data/train_6_LiDaWei_20161109_012656_fil_seg_bcr',
        '../data/train_7_ChenYunKun_20161109_021658_fil_seg_bcr',]

for i in range(5):
    instance.append((loadmat(mat[i]))['instance'].swapaxes(0, 2))
    label.append(np.ravel(loadmat(mat[i])['label']))

ica = FastICA(n_components=1000, whiten = True)
svm = SVC(kernel='rbf', C = 2.15443469e+06, gamma = 2e-08) 

result = []
testScore = []
for i in range(5):
    print("validation", str(i + 1))
    trainXSup = np.concatenate(circSlice(instance, i , 4), axis = 0)
    trainY = np.concatenate(circSlice(label, i, 4), axis = 0)
    testXSup = instance[(i + 4) % 5]
    testY = label[(i + 4) % 5]
    
    labelEstimated = []
    for c in channel:
        trainX = trainXSup[:, :, c]
        trainX = trainX.reshape(240, trainX.shape[1] * trainX.shape[2])
        testX = testXSup[:, :, c]
        testX = testX.reshape(60, testX.shape[1] * testX.shape[2])

        trainX = ica.fit_transform(trainX)

        svm.fit(trainX, trainY)
        testX = ica.transform(testX)
        labelEstimated.append(svm.predict(testX))
        print("------------------")
    result.append([])
    for p in range(60):
        sum = 0
        for j in range(len(channel)):
            sum += labelEstimated[j][p] * channelWeight(j)
        if sum > 0:
            result[i].append(1)
        else:
            result[i].append(-1)
    print("validation", str(i + 1), "score:", str(accuracy_score(testY, result[i])))
    testScore.append(accuracy_score(testY, result[i]))
    print("------------------")
        
#member = [0, 1, 2, 3, 4]
#plt.plot(member, testScore)
#plt.show()
print(np.mean(testScore))





