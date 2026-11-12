//

#include <iostream>
#include <vector>

using namespace std;

// Algorithm 1 Implementation
bool fail_lecture(const vector<int>& attendance_records) {
	int absent_count = 0;

	// changed int to size_t to fix signedness warning
	for (size_t i = 1; i < attendance_records.size(); ++i) {	// fault statement Q1
		absent_count += (attendance_records[i] == 0);
	}
	return absent_count >= 3;
}

// main funtion for testing expected/actual output
int main() {
	vector<int> question4_test = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
	cout << "Question 4 Output (Expected: 1): " << fail_lecture(question4_test) << endl;

	vector<int> question5_test = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
	cout << "Question 5 Output (Expected: 1): " << fail_lecture(question5_test) << endl;

	return 0;
}

/* Question Answers:

1. Yes there is a logical fault in the program. The for loop initializes at 1, but C++ arrays and vectors index's start at 0, so the student's attendance for the first lecture is skipped.
   Fault Statement: for (int i = 1; i < attendance_records.size(); ++i);

2. A test is not possible since the function should always pass a vector of exactly 10 values. Therefore the loop condition is always true and the fault statement will always be reached and executed every time the functino is called.

3. A test is possible where the error state is avoided. For this to happen, absent_count would have to stay the same as if the fault did not happen. Since the fault skips the first element, setting this value to 1 wouldn't change absent_count and the correct count would happen.
   Test Case: {1, 0, 0, 0, 1, 1, 1, 1, 1, 1}

4. Attendance Record: {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}
   - The expected absent_count is 4, so the student would fail the course.
   - The actual absent_count is 3, so the student fails the course.

   An error state happens because the internal state of absent_count is different from the expected output (4) is different from the actual output (4). No failure occurs since both 3 and 4 return true.

5. Attendance Record: {0, 0, 0, 1, 1, 1, 1, 1, 1, 1}
   - The expected absent_count is 3, so the student would fail the course.
   - The actual absent_count is 2, so the student would pass the course.

   The observable failure happens because of the element in index 0 being skipped. This changed the actual value of absent_count to be 2 instead of 3, which is the cutoff for a student passing or failing a the course.

*/
