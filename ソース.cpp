#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

/**/
class UnicodeOne {
public:
	int Parse(const char8_t X[]) {
		C[0] = X[0];
		if ((X[0] & (1 << 7)) != 0) { return 1; }
		C[1] = X[1];
		C[2] = 0;
		if ((X[1] & (1 << 7)) != 0) { return 2; }
		C[2] = X[2];
		return 3;
	}

	std::size_t Size() {
		if (C[0] == 0 && C[1] != 0) { return 0; }
		if ((C[0] & (1 << 7)) != 0) { return 1; }
		if ((C[1] & (1 << 7)) != 0) { return 2; }
		return 3;
	}

	std::int8_t& operator [](std::size_t i) {
		return C[i];
	}
	const std::int8_t& operator [](std::size_t i) const{
		return C[i];
	}
protected:
	std::int8_t C[3] = {};
};
	std::ostream& operator<<(std::ostream& OS,UnicodeOne& C) {

		if ((C[1] & (1 << 7)) != 0) { C[2] = u8'\0'; }
		
		//const char8_t X[4] = { C[0],C[1],C[2],u8'\0' };
		const std::int8_t X[4] = { C[0],C[1],C[2],u8'\0' };
		OS << X;
		return OS;
	}
	std::wostream& operator<<(std::wostream& OS,UnicodeOne& C) {

		if ((C[1] & (1 << 7)) != 0) { C[2] = u8'\0'; }
		
		//const char8_t X[4] = { C[0],C[1],C[2],u8'\0' };
		const std::int8_t X[4] = { C[0],C[1],C[2],u8'\0' };
		OS << X;
		return OS;
	}
/**/


/**/
int main() {
	UnicodeOne UO;

	const char8_t A[] = u8"‚ \0";
	const char8_t B[] = u8"‚¦\0";
	char8_t C[] = u8"‚ ";
	//char D[] = u8"‚ ";
	UO.Parse(C);
	std::wcout << UO <<":"<<C<< std::endl;

	return 0;
}