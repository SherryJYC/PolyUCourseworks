
# coding: utf-8

# In[1]:

import numpy as np
import pandas as pd
from sklearn.grid_search import GridSearchCV


# In[2]:

data = pd.read_csv('./data.csv')


# In[3]:

y = data['y']


# In[4]:

X = data.drop(['y'],axis=1)


# In[5]:

from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import RandomForestClassifier, VotingClassifier

lr = LogisticRegression(random_state=1, fit_intercept=True)
rf = RandomForestClassifier(random_state=1, n_estimators=42, max_features='log2', min_samples_leaf=71, max_depth=2, oob_score=True)
nb = GaussianNB()
svm1 = SVC(C=0.1, kernel='linear', tol=0.0001)
svm2 = SVC(C=0.1, kernel='linear', tol=0.0001)


# ### 第一部分：单分类器调参

# In[6]:


#RF
# param = {
#     'n_estimators':[42],
#     'max_features':['log2'],
#     'min_samples_leaf' : [71],
#     'max_depth' : [2],
#     'oob_score' : [True]
# }

# gsearch = GridSearchCV(estimator = rf, cv=6, param_grid=param， n_jobs = -1)


# In[7]:

# param = {
#     'C' : [0.1],
#     'kernel' : ['linear'],
#     'tol' : [0.0001]
# }
# gsearch = GridSearchCV(estimator = svm1, cv=6, param_grid=param, n_jobs = -1)


# In[8]:

# param ={
#     'fit_intercept' : [True, False]
# }

# gsearch = GridSearchCV(estimator = lr, cv=6, param_grid=param, n_jobs = -1)


# In[9]:

# no need
#gsearch = GridSearchCV(estimator = nb, param_grid=param, cv=6, n_jobs = -1)


# In[10]:

#gsearch.fit(X, y)


# In[11]:

#记录最优参数
#gsearch.best_params_


# In[12]:

#gsearch.best_score_


# ### 第二部分：确定各单分类器

# In[6]:

#利用第一部分确定的参数，训练各个最终单分类器
rf.fit(X,y)
lr.fit(X,y)
svm1.fit(X,y)
svm2.fit(X,y)
nb.fit(X,y)


# In[7]:

data_ensemble = []


# In[8]:

#将各单分类器的预测结果综合
data_ensemble.append(rf.predict(X).reshape(-1, 1))
data_ensemble.append(lr.predict(X).reshape(-1, 1))
data_ensemble.append(svm1.predict(X).reshape(-1, 1))
data_ensemble.append(svm2.predict(X).reshape(-1, 1))
data_ensemble.append(nb.predict(X).reshape(-1, 1))
data_ensemble = np.concatenate(data_ensemble, axis=1)


# ### 第三部分：综合分类器调参

# In[10]:

#训练综合分类器
svm_ensemble = SVC(C=0.00001, kernel='poly', gamma=100, degree=2)


# In[11]:

#设置综合分类器的参数
param_ensemble={
}
gsearch_ensemble = GridSearchCV(estimator = svm_ensemble, cv=6, param_grid=param_ensemble, n_jobs=-1)


# In[ ]:

gsearch_ensemble.fit(data_ensemble, y)


# In[19]:

#记录最优参数
gsearch_ensemble.best_score_


# In[20]:

gsearch_ensemble.best_params_

