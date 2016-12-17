function mSup = concatenate(m, start, length)
    mSup = m{start};
    for j = 2 : length
        next = m{mod(start + j - 2, size(m)) + 1};
        mSup = [mSup; next];
    end
end