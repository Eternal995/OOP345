#include "WritingRecord.h"

#include "EmpProfile.h"
#include "GeneratingList.h"

using namespace std;

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;
        // TODO: Add your code here to build a list of employees
        //         using raw pointers
        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    if (!activeEmp.checkLuhn(emp[i].id))
                        throw std::string("*** Invalid Employee ID");
                    EmployeeWage* ew = new EmployeeWage(emp[i].name, sal[j].salary);
                    try {
                        ew->rangeValidator();
                    } catch (const std::string& err) {
                        delete ew;
                        throw err;
                    }
                    activeEmp += ew;
                    break;
                }
            }
        }

        return activeEmp;
    }

    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;
        // TODO: Add your code here to build a list of employees
        //         using smart pointers
        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    if (!activeEmp.checkLuhn(emp[i].id))
                        throw std::string("*** Invalid Employee ID");

                    std::unique_ptr<EmployeeWage> ew(new EmployeeWage(emp[i].name, sal[j].salary));
                    ew->rangeValidator();
                    activeEmp += ew.get();
                    break;
                }
            }
        }
        return activeEmp;
    }
}