function score = score(testY, label)
count = 0;
for k = 1: 60
    if testY(k) == label(k)
        count = count + 1;
    end
end
score = count / 60;
end
