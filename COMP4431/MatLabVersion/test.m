d = dir('.\data\*.mat');
instance = cell(length(d), 1);
label = cell(length(d), 1);
for i = 1 : length(d)
    mat = load(strcat('.\data\',d(i).name));
    instance{i} = mat.instance;
    label{i} = mat.label;
end

index = 9;

testX = instance{index};
testY = label{index};
result = (1:60);
for i = 1:60
    input = squeeze(testX(:, :, i));
    result(i) = classifier(input);
end

