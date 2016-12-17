function label = classifier(testData)
    channel1 = [51, 52, 58, 59, 60, 64, 65, 66, 67, 69, 70, 71];
    channel2 = [76, 77, 83, 84, 85, 89, 90, 91, 92, 95, 96, 97];
    channel3 = [51, 52, 53, 57, 58, 59, 60, 61, 63, 64, 65, 66,...
        67, 69, 70, 71, 72, 74, 77, 78, 79, 84, 85, 86, 87, 89,...
        90, 91, 92, 93, 95, 96, 97, 98, 100, 101];
    channel4 = [58, 59, 64, 65, 66, 69, 70];
    channel5 = [83, 84, 89, 90, 91, 95, 96];
    channel6 = 1:128;
    channel = {channel1;channel2;channel3;channel4;channel5;channel6};
    
    persistent classifiers;
    if isempty(classifiers)
        classifiers = cell(6, 3);
        for i = 1 : 6
            classifiers{i}{1} = load(strcat(num2str(i), 'pcaMu.mat'));
            classifiers{i}{1} = classifiers{i}{1}.mu;
            classifiers{i}{2} = load(strcat(num2str(i), 'pcaCoef.mat'));
            classifiers{i}{2} = classifiers{i}{2}.coeffX;
            classifiers{i}{3} = load(strcat(num2str(i), 'svm.mat'));
            classifiers{i}{3} = classifiers{i}{3}.svm;
            classifiers{i}{4} = load(strcat(num2str(i), 'rf.mat'));
            classifiers{i}{4} = classifiers{i}{4}.rf;
            classifiers{i}{5} = load(strcat(num2str(i), 'lr.mat'));
            classifiers{i}{5} = classifiers{i}{5}.lr;
        end
    end

    labelByChannel = (1:6);
    for i = 1:6
        labelByChannel(i) = classifierSon(testData, channel{i}, classifiers{i});
    end 
  
    weightedLabel = 0;
    channelWeight = [1.8, 1.8, 2, 1.8, 1.8, 1.8];
    for i = 1 : 6
        weightedLabel = weightedLabel + channelWeight(i) * labelByChannel(i);
    end
    
    if weightedLabel > 0
        label = 1;
    else
        label = -1;
    end

    



