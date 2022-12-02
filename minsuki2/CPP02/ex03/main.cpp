/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/02 21:58:00 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {

	// TEST 1
	// {
	//     Point const A(1, 1); Point const B(5, 1);
	//     Point const C(3, 4); Point const D(3, 2);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	// TEST 2
	// {
	//     Point const A(-2.14f, -1.71f); Point const B(9, -2);
	//     Point const C(-1.47f, 6.87f); Point const D(3.71f, 2.48f);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	// // TEST 3
	// {
	//     Point const A(-2.14f, -1.71f); Point const B(9, -2);
	//     Point const C(-1.47f, 6.87f); Point const D(3.70942f, 2.48338f);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	// // TEST 4 삼각형 위의 한점 오차
	// {
	//     Point const A(-2.14f, -1.71f); Point const B(9, -2);
	//     Point const C(-1.47f, 6.87f); Point const D(3.7086f, 2.48256f);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
    //
	// }

	// // TEST 5 삼각형 위의 한점 오차
	// {
	//     Point const A(-2.14f, -1.71f); Point const B(9, -2);
	//     Point const C(-1.47f, 6.87f); Point const D(3.7085984566f, 2.4825636814f);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	// // TEST 6 삼각형 확실한 위의 한점 오차
	// {
	//     Point const A(-2.14f, -1.71f); Point const B(9, -2);
	//     Point const C(-1.47f, 6.87f); Point const D(-2.14, -1.71f);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	// // TEST 7 삼각형 확실한 위의 한점 오차
	// {
	//     Point const A(1, 1); Point const B(4, 4);
	//     Point const C(6.16f, 0.768f); Point const D(3, 3);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	// TEST 큰 삼각형
	// {
	//     Point const A(-4223.5390773695,-2765.9308930337);
	//     Point const B(1650.1410106947,6486.6941920712);
	//     Point const C(4176.4550270664,-3776.4564995981);
	//     Point const D(39.6158252578,770.9087299416);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }
    //
	// // TEST 중간 삼각형
	// {
	//     Point const A(-1949.856462635,-1502.7738848282);
	//     Point const B(44.6282671718,2659.6940799642);
	//     Point const C(1729.0883237063,-1344.8792588026);
	//     Point const D(39.6158252578,770.9087299416);
	//     bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
	//                       std::cout << "[bsp] : " << "False" << std::endl;
	// }

	{
		Point const A(264.5687252877,90.3863846186);
		Point const B(157.7012596696,239.6323279841);
		Point const C(1729.0883237063,-1344.8792588026);
		Point const D(158.8410412611,138.3678481236);
		bsp(A, B, C, D) ? std::cout << "[bsp] : " << "True" << std::endl :
						  std::cout << "[bsp] : " << "False" << std::endl;
	}
	return 0;
}
