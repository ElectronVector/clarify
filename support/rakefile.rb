
single_case_expected = %{test_single_case.c: Running Tests...
+ Given: A
 + When: 1
  + Then: a
+ Given: A
 + When: 1

---------------------------------------------------
test_single_case.c: Test Results
---------------------------------------------------
Tested: 1
Passed: 1
Failed: 0
}

clarify_expected = %{test_clarify.c: Running Tests...
+ Given: two positive integers (1)
 + When: they are added together
  + Then: the result is correct
+ Given: two positive integers (1)
 + When: they are added together
  + Then: something else happens
+ Given: two positive integers (1)
 + When: they are multiplied together
  + Then: the value is correct
+ Given: two positive integers (1)
 + When: they are multiplied together

---------------------------------------------------
test_clarify.c: Test Results
---------------------------------------------------
Tested: 3
Passed: 3
Failed: 0
}

failure_expected = %{test_failure.c: Running Tests...
---------------------------------------------------
Test at test_failure.c:5 FAILED
---------------------------------------------------
  Given: given
   When: when
   Then: then
---------------------------------------------------
FAILED at test_failure.c:12:
  ASSERT( false )
---------------------------------------------------


---------------------------------------------------
test_failure.c: Test Results
---------------------------------------------------
Tested: 1
Passed: 0
Failed: 1
}

task :default do
    run_test "single_case", 0, single_case_expected
    run_test "failure",     1, failure_expected
    run_test "clarify",     0, clarify_expected
end

def run_test(test_name, expected_result, expected_output)
    sh "gcc -W -Wall test_#{test_name}.c -o #{test_name}"
    result = `./#{test_name}`
    puts result
    puts "#{test_name} exited with #{$?.exitstatus}"
    if (result == expected_output) && ($?.exitstatus == expected_result)
        puts "PASS"
    else
        if (result != expected_output)
            compare_output(expected_output, result)
        end
        puts "**********FAIL****************************************"
    end
end

# def compare_output (expected, actual)
#     expected.each_line do |line|
#         puts "line: #{line}"
#     end
# end