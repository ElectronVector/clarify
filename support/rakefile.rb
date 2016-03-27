
task :default => %w[ clarify ]

expected = %{test_clarify.c: Running Tests...
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

task :clarify do
    # Generate the preprocessed file.
    # sh "gcc -E test_behav.c > test_behav.preprocessed"
    # Build and run the test binary.
    sh "gcc -W -Wall test_clarify.c -o clarify"
    result = `./clarify`
    puts result
    puts "clarify exited with #{$?.exitstatus}"
    if (result == expected) and ($?.exitstatus == 0)
        puts "******PASS"
    else
        puts "******FAIL"
    end
end
