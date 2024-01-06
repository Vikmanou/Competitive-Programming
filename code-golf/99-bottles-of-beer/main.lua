a='%s bottle%s of beer on the wall, %s bottle%s of beer.'b='Take one down and pass it around, %s bottle%s of beer on the wall.'p=print
for i=99,1,-1 do s=i==1 and''or's'p(a:format(i,s,i,s))p(b:format(i-1==0 and'no more'or i-1,(i-1==1 and'')or's'),'\n')end
p(a:format('No more','s','no more','s'))p('Go to the store and buy some more, 99 bottles of beer on the wall.')