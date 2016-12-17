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

for i = 1 : sampleNum
    mat = load(strcat('.\data\',d(i).name));
    instance{i} = mat.instance;
    label{i} = mat.label;
    instance{i} = permute(instance{i}, [3,2,1]);
end

validScore = (1:sampleNum);
validTime = length(d);
validStart = 3;
for i = validStart : (validStart + validTime - 1)
    fprintf('validation %i on %s\n', i, d(i).name);
    trainXSup = concatenate(instance, i + 1, sampleNum - 1);
    trainY = concatenate(label, i + 1, sampleNum - 1);
    testXSup = instance{i + 1};
    testY = label{i + 1};
  
    labelChannel = cell(length(channel), 1);
    for j = 1 : length(channel)           
        trainX = trainXSup(:,:,channel{j});
        testX = testXSup(:,:,channel{j});
        trainX = trainX - mean(trainX(:, 1:25, :), 2);
        testX = testX - mean(testX(:, 1:25, :), 2);
        
        trainX = reshape(trainX, 60 * (sampleNum - 1), size(trainX,3) * size(trainX,2), 1);
        testX = reshape(testX, 60, size(testX,3) * size(testX,2), 1);
        
        
        [trainX,~] = mapminmax(trainX,-1,1);

        %[trainX,~] = mapstd(trainX);
        %[trainX,ST] = mapstd(trainX);
        %trainX = mapstd('apply', trainX,ST); 
        %[trainX,~] = mapminmax(trainX,-50,50);
        
        
        [testX,~] = mapminmax(testX,-1,1);

        %[testX,~] = mapstd(testX);
        %testX = mapstd('apply', testX,ST); 
        %testX = mapstd('apply', testX,ST); 
        %[testX,~] = mapminmax(testX,-50,50);
        
        mu = mean(trainX);
        [coeffX,trainX] = pca(trainX,'NumComponents',102);
        svm = fitcsvm(trainX, trainY, 'KernelFunction', 'rbf','BoxConstraint', 2000000, 'KernelScale', 'auto');
        rf = TreeBagger(250, trainX, trainY);
        lr = logitBin(permute(trainX, [2, 1]), permute(trainY, [2, 1]), 200000);
        
        testX = bsxfun(@minus, testX, mu);
        testX = testX * coeffX;
        labelSVM = predict(svm, testX);
        labelRF = predict(rf, testX);
        labelRF = str2double(labelRF);
        labelLR = logitBinPred(lr, permute(testX, [2, 1]));
        labelLR = permute((labelLR * 2 - 1) * -1, [2, 1]);

        fprintf('channel %i: svmScore%i\n', j, score(testY, labelSVM));   
        fprintf('channel %i: rfScore%i\n', j, score(testY, labelRF));
        fprintf('channel %i: lrScore%i\n', j, score(testY, labelLR));
        
        labelChannel{j} = voting(labelSVM, labelRF, labelLR);
        fprintf('channel %i: score%i\n', j, score(testY, labelChannel{j}));        
        fprintf('----------------------------\n');
    end
    
    channelDecision = voting(labelChannel{:});
    validScore(i) = score(testY, channelDecision);
    fprintf('validation %i score: %i\n', i, validScore(i))
    fprintf('----------------------------\n');       
end

meanValidScore = mean(validScore);


