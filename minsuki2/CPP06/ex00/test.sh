#!/bin/bash

echo "input: <0> "
./convert 0

echo "input: <10.0>"
./convert 10.0

echo "input: <1000>"
./convert 1000

echo "input: <f>"
./convert f

echo "input: <42.0f>"
./convert 42.0f

echo "input: <42.0fq>"
./convert 42.0fq

echo "input: <nan>"
./convert nan

echo "input: <inf>"
./convert inf

echo "input: <-inff>"
./convert -inff

echo "input: <test>"
./convert test

echo "input: <10.ewrewrf>"
./convert 10.ewrewrf

echo "input: <11111111>"
./convert 11111111

echo "input: <111111>"
./convert 111111

echo "input: <1111111111111>"
./convert 1111111111111

echo "input: <111111111111111111111111111111111111111111111111111111111>"
./convert 111111111111111111111111111111111111111111111111111111111
