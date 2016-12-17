function label = classifierSon(testData, channel, classifier)
    testX = testData(channel,:);
    testX = reshape(testX, 1, size(testX,1)  *size(testX,2));
    testX = testX - mean(testX(:, 1:25, :), 2);
    [testX,~] = mapminmax(testX,-1,1);

    mu = classifier{1};
    coef = classifier{2};
    svm = classifier{3};
    rf = classifier{4};
    lr = classifier{5};

    testX = bsxfun(@minus, testX, mu);
    testX = testX * coeffX;
    labelSVM = predict(svm, testX);
    labelRF = predict(rf, testX);
    labelRF = str2double(labelRF);
    labelLR = logitBinPred(lr, permute(testX, [2, 1]));
    labelLR = permute((labelLR * 2 - 1) * -1, [2, 1]);
    
    label = voting(labelSVM, labelRF, labelLR);



