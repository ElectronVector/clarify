task :default do
    # Build and run the test binary.
    sh "gcc -W -Wall test_power_button.c power_button.c -o test_power_button"
    sh "./test_power_button" do |ok|
    end
end