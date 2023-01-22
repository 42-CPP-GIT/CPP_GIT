#!/bin/bash

echo "input: <0> "
./convert 0
echo

echo "input: <10.0>"
./convert 10.0
echo

echo "input: <1000>"
./convert 1000
echo

echo "input: <f>"
./convert f			# CASE 판도라 상자로...
echo

echo "input: <42.0f>"
./convert 42.0f
echo

echo "input: <42.0fq>"
./convert 42.0fq
echo

echo "input: <nan>"
./convert nan
echo

echo "input: <inf>"
./convert inf
echo

echo "input: <-inff>"
./convert -inff
echo

echo "input: <test>"
./convert test
echo

echo "input: <10.ewrewrf>"
./convert 10.ewrewrf
echo

echo "input: <11111111>"
./convert 11111111
echo

echo "input: <111111>"
./convert 111111
echo

echo "input: <1111111111111>"
./convert 1111111111111
echo

echo "input: <111111111111111111111111111111111111111111111111111111111>"
./convert 111111111111111111111111111111111111111111111111111111111
echo

