
# coding: utf-8

# In[10]:

get_ipython().magic('matplotlib inline')
import pandas as pd
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
import operator
import seaborn as sns
import warnings
from pandas.tools.plotting import radviz

# data_train=pd.read_excel("./data_CREDIT.xlsx",sheetname=1,skiprows=[0])
data_train=pd.read_csv("./credit_data.csv")
data_train=data_train.replace('?',np.nan)
#print(data_train.iloc[83])
#data_train.info()
sns.set(style="white", color_codes=True)
data_train.head()


# In[11]:

data_train['A16'].value_counts()


# In[12]:

fig = plt.figure()
fig.set(alpha=0.2)  # 设定图表颜色alpha参数

Survived_0 = data_train.A1[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A1[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A1")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A4[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A4[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A4")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A5[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A5[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A5")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A6[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A6[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A6")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A7[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A7[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A7")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A9[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A9[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A9")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A10[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A10[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A10")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A11[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A11[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A11")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A12[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A12[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A12")
plt.ylabel("A16")
plt.show()

Survived_0 = data_train.A13[data_train.A16 == '+'].value_counts()
Survived_1 = data_train.A13[data_train.A16 == '-'].value_counts()
df=pd.DataFrame({'no':Survived_1, 'yes':Survived_0})
df.plot(kind='bar', stacked=True)
plt.title("title")
plt.xlabel("A13")
plt.ylabel("A16")
plt.show()


# In[13]:

from sklearn.ensemble import RandomForestRegressor
#from sklearn.neighbors import KNeighborsRegressor

### 使用 RandomForestClassifier 填补缺失的年龄属性
def set_missing_a2(df):

    # 把已有的数值型特征取出来丢进Random Forest Regressor中
    a2_df = df[['A2','A3', 'A8', 'A11', 'A15']]
    
    a14_df = df[['A14','A3', 'A8', 'A11', 'A15']]

    known_a2 = a2_df[a2_df.A2.notnull()].as_matrix()
    unknown_a2 = a2_df[a2_df.A2.isnull()].as_matrix()
    print(unknown_a2.shape)
    known_a14 = a14_df[a14_df.A14.notnull()].as_matrix()
    unknown_a14 = a14_df[a14_df.A14.isnull()].as_matrix()

    y2 = known_a2[:, 0]
    y14 = known_a14[:, 0]

    X2 = known_a2[:, 1:]
    X14 = known_a14[:, 1:]

    rfr = RandomForestRegressor(random_state=0, n_estimators=2000, n_jobs=-1)
    rfr2 = RandomForestRegressor(random_state=0, n_estimators=2000, n_jobs=-1)
    #knn=KNeighborsRegressor(weights='distance')
    rfr.fit(X2, y2)
    rfr2.fit(X14,y14)

    # 用得到的模型进行未知年龄结果预测
    predictedA2 = rfr.predict(unknown_a2[:, 1::])
    predictedA14 = rfr2.predict(unknown_a14[:, 1::])
    #print(predictedA2)
    #print(predictedA14)

    # 用得到的预测结果填补原缺失数据
    df.loc[ (df.A2.isnull()), 'A2' ] = predictedA2
    df.loc[ (df.A14.isnull()), 'A14' ] = predictedA14

    return df, rfr, rfr2

data_train, rfr, rfr2 = set_missing_a2(data_train)
data_train['A2']=data_train['A2'].astype('float64')
data_train['A14']=data_train['A14'].astype('float64')


# In[ ]:

def numberize(df):
    df.loc[df.A16=='+','A16']=1
    df.loc[df.A16=='-','A16']=0
    df['A16']=df['A16'].astype('float64')

def adjust_superbig(df):
    df.loc[df.A14>1000,'A14']=1000
    df.loc[df.A15>10000,'A15']=10000
    df.loc[df.A11>25,'A11']=25
    df.loc[df.A8>20,'A8']=20
    
numberize(data_train)
adjust_superbig(data_train)


# In[ ]:

sns.jointplot(x="A2", y="A3", data=data_train, size=5)


# In[ ]:

sns.FacetGrid(data_train, hue="A16", size=5).map(plt.scatter, "A2", "A3").add_legend()


# In[2]:

sns.FacetGrid(data_train, hue="A16", size=6).map(sns.kdeplot, "A8").add_legend()
sns.FacetGrid(data_train, hue="A16", size=6).map(sns.kdeplot, "A11").add_legend()
sns.FacetGrid(data_train, hue="A16", size=6).map(sns.kdeplot, "A15").add_legend()
#A8 A11 a15 can make following new features
#A8>5 A11>4 A15>1200


# In[3]:

sns.pairplot(data_train.drop(data_train.columns[[0,3,4,5,6,8,9,11,12]], axis=1), hue="A16", size=3)
#sns.pairplot(data_train.drop(data_train.columns[[0,3,4,5,6,8,9,11,12]], axis=1), hue="A16", size=3, diag_kind="kde")


# In[4]:

radviz(data_train.drop(data_train.columns[[0,3,4,5,6,8,9,11,12]], axis=1), "A16")


# In[5]:

#add attributes
def add_attributes(df):
    df['A8_big']=0
    df.loc[df.A8>5,'A8_big']=1
    df['A11_big']=0
    df.loc[df.A8>4,'A11_big']=1
    df['A15_big']=0
    df.loc[df.A8>1200,'A15_big']=1
add_attributes(data_train)


# In[6]:

dummies_A1 = pd.get_dummies(data_train['A1'], prefix= 'A1')
dummies_A4 = pd.get_dummies(data_train['A4'], prefix= 'A4')
dummies_A5 = pd.get_dummies(data_train['A5'], prefix= 'A5')
dummies_A6 = pd.get_dummies(data_train['A6'], prefix= 'A6')
dummies_A7 = pd.get_dummies(data_train['A7'], prefix= 'A7')
dummies_A9 = pd.get_dummies(data_train['A9'], prefix= 'A9')
dummies_A10 = pd.get_dummies(data_train['A10'], prefix= 'A10')
dummies_A12 = pd.get_dummies(data_train['A12'], prefix= 'A12')
dummies_A13 = pd.get_dummies(data_train['A13'], prefix= 'A13')

df = pd.concat([data_train, dummies_A1, dummies_A4, dummies_A5, dummies_A6, dummies_A7, dummies_A9, dummies_A10, dummies_A12, dummies_A13], axis=1)
df.drop(['A1', 'A4', 'A5', 'A6', 'A7', 'A9', 'A10', 'A12', 'A13'], axis=1, inplace=True)
df.head()


# In[7]:

import sklearn.preprocessing as preprocessing
scaler = preprocessing.StandardScaler()
a2_scale_param = scaler.fit(df['A2'].values.reshape(-1,1))
df['A2_scaled'] = scaler.fit_transform(df['A2'].values.reshape(-1,1), a2_scale_param)
a3_scale_param = scaler.fit(df['A3'].values.reshape(-1,1))
df['A3_scaled'] = scaler.fit_transform(df['A3'].values.reshape(-1,1), a3_scale_param)
a8_scale_param = scaler.fit(df['A8'].values.reshape(-1,1))
df['A8_scaled'] = scaler.fit_transform(df['A8'].values.reshape(-1,1), a8_scale_param)
a11_scale_param = scaler.fit(df['A11'].values.reshape(-1,1))
df['A11_scaled'] = scaler.fit_transform(df['A11'].values.reshape(-1,1), a11_scale_param)
a14_scale_param = scaler.fit(df['A14'].values.reshape(-1,1))
df['A14_scaled'] = scaler.fit_transform(df['A14'].values.reshape(-1,1), a14_scale_param)
a15_scale_param = scaler.fit(df['A15'].values.reshape(-1,1))
df['A15_scaled'] = scaler.fit_transform(df['A15'].values.reshape(-1,1), a15_scale_param)
df=df.drop(df.columns[0:6],axis=1)
df.head()


# In[9]:

radviz(df.drop(df.columns[1:44], axis=1), "A16")


# In[8]:

# feature selection begins

import numpy as np
from scipy.stats import pearsonr
np.random.seed(0)
size = 300
x = df.A2_scaled
y=df.A3_scaled
# pearsonr(x, y)的输入为特征矩阵和目标向量
print("Lower noise", pearsonr(x, y))


# In[55]:

num_df=df[['A2_scaled','A3_scaled','A8_scaled','A11_scaled','A14_scaled','A15_scaled']]
df.corr(method='pearson')


# In[74]:

from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2
from sklearn.feature_selection import f_regression
df_num=df.ix[:,'A2_scaled':'A15_scaled']
df_other=df.ix[:,'A8_big':'A13_s']
#print(df.info())
#X=df.ix[:,1:]
X=df_other
X2=df_num
y=df.A16
print(X.head())
X_new = SelectKBest(chi2, k=20).fit_transform(X, y)
#X2_new = SelectKBest(f_regression, k=5).fit_transform(X, y)


# In[ ]:



