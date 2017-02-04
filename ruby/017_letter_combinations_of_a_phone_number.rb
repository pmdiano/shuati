# @param {String} digits
# @return {String[]}

DIGITS = {
    '0' => '',
    '1' => '',
    '2' => 'abc',
    '3' => 'def',
    '4' => 'ghi',
    '5' => 'jkl',
    '6' => 'mno',
    '7' => 'pqrs',
    '8' => 'tuv',
    '9' => 'wxyz'
}

def letter_combinations(digits)
    res = []
    return res if digits.empty?

    dfs(digits, 0, '', res)
    res
end

def dfs(digits, pos, str, res)
    if pos == digits.length
        res.push(str)
        return
    end

    DIGITS[digits[pos]].split('').each do |c|
        dfs(digits, pos+1, str+c, res)
    end
end
