
function label = train(testData)
    addpath(genpath(pwd));
    channel1 = [51, 52, 58, 59, 60, 64, 65, 66, 67, 69, 70, 71];
    channel2 = [76, 77, 83, 84, 85, 89, 90, 91, 92, 95, 96, 97];
    channel3 = [51, 52, 53, 57, 58, 59, 60, 61, 63, 64, 65, 66,...
        67, 69, 70, 71, 72, 74, 77, 78, 79, 84, 85, 86, 87, 89,...
        90, 91, 92, 93, 95, 96, 97, 98, 100, 101];
    channel4 = [58, 59, 64, 65, 66, 69, 70];
    channel5 = [83, 84, 89, 90, 91, 95, 96];
    channel6 = 1:128;
    channel = {channel1;channel2;channel3;channel4;channel5;channel6};

    d = dir('.\data\*.mat');
    sampleNum = length(d);
    instance = cell(length(d), 1);
    label = cell(length(d), 1);
    
    for i = 1 : length(d)
        mat = load(strcat('.\data\',d(i).name));
        instance{i} = mat.instance;
        label{i} = mat.label;
        instance{i} = permute(instance{i}, [3,2,1]);
    end
    
    trainXSup = concatenate(instance, 1, sampleNum);
    trainY = concatenate(label, 1, sampleNum);

    for j = 1:6
        trainX = trainXSup(:,:,channel{j});
        trainX = trainX - mean(trainX(:, 1:25, :), 2);
        trainX = reshape(permute(trainX, [1,3,2]), 60 * sampleNum, size(trainX,3)*size(trainX,2), 1);
    
        [trainX,~] = mapminmax(trainX,-1,1);
    
        mu = mean(trainX);
        [coeffX,trainX] = pca(trainX,'NumComponents',102);
        svm = fitcsvm(trainX, trainY, 'KernelFunction', 'rbf','BoxConstraint', 2154434.69, 'KernelScale', 'auto');
        rf = TreeBagger(250, trainX, trainY);
        lr = logitBin(permute(trainX, [2, 1]), permute(trainY, [2, 1]));
        
        pcaMu= strcat(num2str(j), 'pcaMu.mat');
        pcaCoef = strcat(num2str(j), 'pcaCoef.mat');
        svmName = strcat(num2str(j), 'svm.mat');
        rfName = strcat(num2str(j), 'rf.mat');
        lrName = strcat(num2str(j), 'lr.mat');
        
        save(pcaMu,'mu');
        save(pcaCoef,'coeffX');
        save(svmName,'svm');
        save(rfName,'rf');
        save(lrName,'lr');   
    end
end

