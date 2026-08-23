B=1e7 L=146 C=table.create
function A(a,b)r=0 for i=1,L do s=a[i]+b[i]+r if s>=B then a[i]=s-B r=1 else a[i]=s r=0 end end end
function D(a,d)o={}m=0 for i=L,1,-1 do c=m*B+a[i];o[i]=c//d m=c%d end return o end
function M(a,m)r=0 for i=1,L do c=a[i]*m+r a[i]=c%B r=c//B end end
function Z(a)for i=1,L do if a[i]~=0 then return 0 end end end
S=C(L,0)s=C(L,0)s[L]=1e5 t=D(s,3)k=0
while Z(t)==0 do A(S,D(t,2*k+1))t=D(t,9)k+=1 end
M(S,2)p={}for i=L,1,-1 do p[#p+1]=("%07d"):format(S[i])end
g=table.concat(p)g=g:sub(#g-1019,#g);print("0."..g:sub(1,1e3))