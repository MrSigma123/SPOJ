# Initialize lists to store the inputs and results
test_cases = []

# Read 10 test cases
for _ in range(10):
    total_apples = int(input())
    difference_apples = int(input())
    test_cases.append((total_apples, difference_apples))

# Process all test cases and store the results
results = []

for total_apples, difference_apples in test_cases:
    klaudia_apples = (total_apples + difference_apples) // 2
    natalia_apples = total_apples - klaudia_apples
    results.append((klaudia_apples, natalia_apples))

# Display the output after processing all input
for klaudia_apples, natalia_apples in results:
    print(klaudia_apples)
    print(natalia_apples)
