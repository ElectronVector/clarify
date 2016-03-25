
task :default => %w[ clarify ]

task :clarify do
    # Generate the preprocessed file.
    # sh "gcc -E test_behav.c > test_behav.preprocessed"
    # Build and run the test binary.
    sh "gcc -W -Wall test_clarify.c -o clarify"
    sh "./clarify" do |ok|
        puts ""
        puts "clarify exited with #{ok}"
    end
end
