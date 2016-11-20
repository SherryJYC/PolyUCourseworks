import numpy as np
from scipy.io import loadmat
import pandas as pd
from sklearn.svm import SVC
from sklearn.model_selection import cross_val_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV


mat1 = loadmat('../data/train_6_LiDaWei_20161109_012656_fil_seg_bcr')
mat2 = loadmat('../data/train_7_ChenYunKun_20161109_021658_fil_seg_bcr')

instance1 = mat1['instance'].swapaxes(0, 2).swapaxes(1, 2).reshape(60, -1)
label1 = np.ravel(mat1['label'])

instance2 = mat2['instance'].swapaxes(0, 2).swapaxes(1, 2).reshape(60, -1)
label2 = np.ravel(mat2['label'])

instance = np.concatenate((instance1, instance2), axis = 0)
label = np.concatenate((label1, label2), axis = 0)

instance, label = shuffle(instance, label)

trainX, testX, trainY, testY = train_test_split(instance, label, test_size=0.25, random_state=1)

clf = svm(trainX, trainY)
clf.score(testX, testY)

def svm(x, y):
    parameters = [{'gamma': [1e-3, 1e-4, 1e-5], 'C': [0.1, 1, 10, 100]}]

    clf = GridSearchCV(SVC(kernel = 'rbf'), parameters, cv = 5)
    clf.fit(x, y)
    print(str(clf.best_params_))
    return clf

def rf(x, y):
    clf = RandomForestClassifier(n_estimators = 200)
    clf = clf.fit(x, y)
    return clf


