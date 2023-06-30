#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::istream;
using std::stringstream;

vector<string> get_vector_of_strings() {
    // Getting raw input string from user
    string raw_input_string = "";
    getline(cin, raw_input_string);

    // Creating stream from raw string for
    // processing
    stringstream raw_input_stream(raw_input_string);
    
    // Placeholder variable for holding individual
    // stream strings
    string stream_section = "";
    vector<string> delimited_strings;

    // Pushing stream sections into vector until
    // stream is empty
    while(raw_input_stream >> stream_section) {
        delimited_strings.push_back(stream_section);
    }

    return delimited_strings;
}

int main() {
    cout << "Enter the names of the students: " << endl;
    vector<string> student_names = get_vector_of_strings();
    vector<int> student_grades;

    typedef vector<string>::size_type vec_sz;
    for(vec_sz i = 0; i != student_names.size(); i++) {
        cout << "Enter grades for " << student_names[i] << ": "; 
        vector<string> student_grade_strings = get_vector_of_strings();
        vector<int> student_grades_buffer;

        for(int i = 0; i != student_grade_strings.size(); i++) {
            student_grades_buffer.push_back(stoi(student_grade_strings[i]));
        }

        int median = 0;

        vec_sz size = student_grades_buffer.size();
        vec_sz mid = size / 2;

        
        median = size % 2 == 0 
            ? (student_grades_buffer[mid] + student_grades_buffer[mid-1]) / 2
            : (student_grades_buffer[mid]);

        student_grades.push_back(median);
    }

    cout << endl;

    typedef vector<int>::size_type vec_sz;
    for(vec_sz i = 0; i != student_grades.size(); i++) {
        cout << student_names[i] << ": " << student_grades[i] << endl;
    }
}
