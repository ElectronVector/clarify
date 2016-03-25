
task :default => %w[ behav ]

task :behav do
    # Generate the preprocessed file.
    sh "gcc -E test_behav.c > test_behav.preprocessed"
    # Build and run the test binary.
    sh "gcc -W -Wall test_behav.c -o behav.exe"
    sh "./behav.exe" do |ok|
        puts ""
        puts "behav exited with #{ok}"
    end
end
