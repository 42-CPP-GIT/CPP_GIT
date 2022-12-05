/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/04 20:33:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// https://www.geogebra.org/geometry?lang=ko

int main(void) {

	std::cout << "\n[TEST 1-1] " << "정수 삼각형 내부 점" << std::endl;
	{
		Point const A(1, 1); Point const B(5, 1);
		Point const C(3, 4); Point const D(3, 2);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_TRUE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 1-2] " << "정수 삼각형 외부 점" << std::endl;
	{
		Point const A(1, 1); Point const B(5, 1);
		Point const C(3, 4); Point const D(1, 3);
		bsp(A, B, C, D) ? std::cout << MSG_BSP <<MSG_TRUE :
						  std::cout << MSG_BSP <<MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 2-1] " << "실수 삼각형 내부 점" << std::endl;
	{
		Point const A(-2.14f, -1.71f); Point const B(9.04f, -2.4f);
		Point const C(-1.47f, 6.87f); Point const D(1, 3);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_TRUE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 2-2] " << "실수 삼각형 모서리 안 쪽" << std::endl;
	{
		Point const A(-2.14f, -1.71f); Point const B(9.04f, -2.4f);
		Point const C(-1.47f, 6.87f); Point const D(3.65385, 2.34747);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_TRUE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 2-3]" << "실수 삼각형 모서리 위 1" << std::endl;
	{
		Point const A(-2.14f, -1.71f); Point const B(9.04f, -2.4f);
		Point const C(-1.47f, 6.87f); Point const D(3.7046,2.30331);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
									<< SET_GREEN MSG_EDGE SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 2-3] " << "실수 삼각형 모서리 위 2" << std::endl;
	{
		Point const A(-2.14f, -1.71f); Point const B(9.04f, -2.4f);
		Point const C(-1.47f, 6.87f); Point const D(3.6545, 2.34785);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
									<< SET_GREEN MSG_ROUND SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 2-4] " << "실수 삼각형 모서리 위 3" << std::endl;
	{
		Point const A(-2.14f, -1.71f); Point const B(9.04f, -2.4f);
		Point const C(-1.47f, 6.87f); Point const D(3.65715,2.35025);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_EDGE SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 2-5] " << "실수 삼각형 모서리 바깥 쪽" << std::endl;
	{
		Point const A(-2.14f, -1.71f); Point const B(9.04f, -2.4f);
		Point const C(-1.47f, 6.87f); Point const D(3.65872,2.35141);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 2-6] " << "실수 삼각형 꼭짓점 1" << std::endl; //
	{
		Point const A(-2.14f, -1.71f); Point const B(9, -2);
		Point const C(-1.47f, 6.87f); Point const D(9, -2);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_VERTEX SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 2-7] " << "실수 삼각형 꼭짓점 2" << std::endl; //
	{
		Point const A(-2.14f, -1.71f); Point const B(9, -2);
		Point const C(-1.47f, 6.87f); Point const D(-1.47, 6.87f);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
									<< SET_GREEN MSG_VERTEX SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 3-1] " << "큰 좌표 + 큰 삼각형" << std::endl; //
	{
		Point const A(147.0123,604.50371);
		Point const B(-623.96877,-304.00371);
		Point const C(1729.0883237063,-1344.8792588026);
		Point const D(10000,10000);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_OVER SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 3-2] " << "작은 좌표 + 큰 삼각형" << std::endl; //
	{
		Point const A(147.0123,604.50371);
		Point const B(-623.96877,-304.00371);
		Point const C(1729.0883237063,-1344.8792588026);
		Point const D(0,0);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_OVER SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 3-3] " << "가능한 중간 삼각형" << std::endl; //
	{
		Point const A(-50.3595,-42.98222);
		Point const B(128.9956,-48.49675);
		Point const C(-19.3387,89.56122);
		Point const D(-33.07943,6.16736);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_TRUE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 3-4] " << "중간 삼각형" << std::endl; //
	{
		Point const A(-50.3595,-42.98222);
		Point const B(128.9956,-48.49675);
		Point const C(-19.3387,89.56122);
		Point const D(100,50);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS << std::endl;
	}

	std::cout << "\n[TEST 3-5] " << "좀 더 큰 삼각형" << std::endl; //
	{
		Point const A(-100,-80);
		Point const B(154.06349,-82.11628);
		Point const C(-52.39148,123.87888);
		Point const D(9.68296,-11.30545);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_OVER SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 3-6] " << "완전 큰 삼각형" << std::endl; //
	{
		Point const A(2874.8032,1472.67529);
		Point const B(2811.47958,-1693.50585);
		Point const C(-2406.38688,-1959.46507);
		Point const D(216.89658,-418.6028);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_OVER SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 3-7] " << "겁나 큰 삼각형" << std::endl; //
	{
		Point const A(-6907.81374,34044.122);
		Point const B(64956.6022,-23695.21971);
		Point const C(-24502.20522,-32120.70305);
		Point const D(4617.11308,3085.27487);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_OVER SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 4-1] " << "일직선 삼각형 정수" << std::endl; //
	{
		Point const A(1, 1);
		Point const B(2, 2);
		Point const C(3, 3);
		Point const D(2, 1);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_EDGE SET_RESET<< std::endl;
	}

	std::cout << "\n[TEST 4-2] " << "일직선 삼각형 실수" << std::endl; //
	{
		Point const A(20.8,10.5);
		Point const B(31.82912,17.67695);
		Point const C(40.42021,23.27697);
		Point const D(30.449,16.78132);
		bsp(A, B, C, D) ? std::cout << MSG_BSP << MSG_TRUE :
						  std::cout << MSG_BSP << MSG_FALSE;
		std::cout << "  =  " << MSG_FALSE << MSG_ANS \
								<< SET_GREEN MSG_EDGE SET_RESET<< std::endl;
	}

	return 0;
}
