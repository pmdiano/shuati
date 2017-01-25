# @param {String} s
# @return {Integer}
def roman_to_int(s)
    return 0 if s.empty?

    map = {
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000
    }

    num = map[s[-1]]
    (s.length - 2).downto(0).each do |i|
        if map[s[i]] < map[s[i+1]]
            num -= map[s[i]]
        else
            num += map[s[i]]
        end
    end
    num
end
