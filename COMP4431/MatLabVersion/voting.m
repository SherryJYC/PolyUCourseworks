function predict = voting(varargin)
    s = size(varargin);
    s = s(2);
    if s == 6
        weight = [1.8, 1.8, 2, 1.8, 1.8, 1.8];%channel weight
    else
        weight = [0.25, 0.25, 0.15];
    end
    
    sum = 0;
    for c = 1 : s
        sum = sum + weight(c) * varargin{c};
    end
    if sum > 0
        predict = 1;
    else
        predict = -1;
    end
end