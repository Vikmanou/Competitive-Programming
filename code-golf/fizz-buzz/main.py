for i in range(1,101):
    f=i%5==0;print(i%3==0 and(f and'FizzBuzz'or'Fizz')or f and'Buzz'or i)