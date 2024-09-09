result = []
ARGV.each do |arg|
    # Skip if not an integer
    next unless arg =~ /^-?\d+$/

    # Convert to integer
    i_arg = arg.to_i
    
    # Insert result at the right position
    inserted = false
    i = 0
    l = result.size
    while !inserted && i < l do
        if result[i] >= i_arg
            result.insert(i, i_arg)
            inserted = true
        else
            i += 1
        end
    end
    result << i_arg unless inserted
end

puts result
