함수 출력
/*

# bsp.cpp > 중간부

	// std::cerr << "--------------------------" << MSG_ENDL;
	// std::cerr << "a        : " << a << ' ' << static_cast<float>(a_bit)/256 << ' '<< std::bitset<32>(a_bit) << MSG_ENDL;
	// std::cerr << "b        : " << b << ' ' << static_cast<float>(b_bit)/256 << ' ' << std::bitset<32>(b_bit) << MSG_ENDL;
	// std::cerr << "cnt_a : " << left_space << MSG_ENDL;
	// std::cerr << "cnt_b : " << max_b_bit << MSG_ENDL;
	// std::cerr << "\nshift   : " << i << MSG_ENDL;
	// std::cerr << "_bitShift : " << std::bitset<32>(1 << (i + 8)) << MSG_ENDL;
	// std::cerr << "b_bit    : " << std::bitset<32>(b_bit) << MSG_ENDL;
	// std::cerr << "ans       : " << std::bitset<32>(res.getRawBits()) << " => " << a << ' ' << b << ' ' << " = "<< res << MSG_ENDL;
	// std::cerr << "res_bit   : " << std::bitset<32>(res_bit) << ' ' << res_bit << MSG_ENDL;
	// std::cerr << "        + : " << std::bitset<32>(add_val) << ' ' << add_val << MSG_ENDL;
	// std::cerr << "a         : " << std::bitset<32>(a_bit) << MSG_ENDL;

# bsp.cpp > _checkTimes 함수 마지막 부
	// std::cerr << "\n<" << a << " * " << b << '>' << MSG_ENDL;
	// std::cerr << "res      : " << std::bitset<32>(res_bit) << " => |" << static_cast<float>(res_bit) / 256 << '|' << MSG_ENDL;
	// std::cerr << "ans      : " << std::bitset<32>(compare_bit) << " => |" << res << '|' << MSG_ENDL;


*/







// # 1 그냥 나누기
	// if ((a != 0 && b != 0) && ((res.getRawBits() / b.getRawBits() != a.getRawBits()))) {
	//     std::cerr << a << " * " << b << " = " << a * b << " b != " << res << MSG_ENDL;
	//     std::stringstream equation;
	//     equation << a << " * " << b;
	//     std::string what(equation.str());
	//     throw what;
	// }

// # 2 범위에 나누기
	// if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
	//     if (b.getRawBits() > 0 ? b.getRawBits() : ~(b.getRawBits() - 1) > (INT_MAX / (a > 0 ? a.getRawBits() : ~(a.getRawBits() - 1)))) {
	// // std::cerr << a << " * " << b << " = " << a * b << " b != " << res << MSG_ENDL;
	//     }
	// }
	// else
	//     if (-b.getRawBits() > 0 ? b.getRawBits() : ~(b.getRawBits() - 1) < (INT_MIN / (a > 0 ? a.getRawBits() : ~(a.getRawBits() - 1)))) {
	//         equation << a << " * " << b << " = " << res;
	//         throw equation.str();
	//     }

	// INT_MAX >= a + b >= INT_MIN

	/*
	INT_MAX - a >= a :> INT_MAX - b < a
	INT_MIN - a <= a :> INT_MIN - b > a

	a + b > INT_MIN
	300 + 3234234234 < INT_MAX
	INT_MAX - 300 > 3234234234(양수)
	300 + -2147394023 > INT_MIN
	INT_MIN + 300 < 2147394023(음수)
	b > 0 ... INT_MAX - a < a

	b < 0 ... INT_MIN - a > a

	0b1111
	b & BIT_SIGN

	a + b <= INT_MAX + +
	a + b >= INT_MIN - -
	INT_MAX - a >= b 	 INT_MAX - a < b			a > only 0    b 모두 가능ㅗ ... 1
	a >= INT_MIN + b     a < INT_MIN + b			a 모두 가능   b > 0			... 2

	- a + b > INT_MIN


	내가 음수면
	INT_MAX + a < b

	쟤가 음수면
	a < INT_MIN - b

	부호 다르면 판단 필요 없음
	+를 판단 - 내가 음수면 판단 할 필요 X
			   내가 양수인데 쟤가 양수일때?




	(1 - 2 * (b_bit & BIT_SIGN)) * ;
	+

		*/

			// || (res_bit < 0 && -res_bit > (a.getRawBits() << max_b_bit))) {




https://clucle.tistory.com/14
https://en.cppreference.com/w/cpp/language/const_cast
https://www.geogebra.org/geometry?lang=ko
