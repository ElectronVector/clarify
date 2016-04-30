task :default do
    # Build and run the test binary.
    sh "gcc -W -Wall test_examples.c -o test_examples"
    sh "./test_examples" do |ok|
    end
end
