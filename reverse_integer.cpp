class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x)
        {
            int pop=x%10;
            if(res>214748364||(res==214748364&&pop>7))
            {
                return 0;
            }
            if(res<-214748364||(res==-214748364&&pop<-8))
            {
                return 0;
            }
            res=res*10+pop;
            x=x/10;
        }
        return res;
    }
};
//这个题目没什么好说的，但是要注意越界问题，这里可以使用long类型定义res。或者也可以像
//我上面所写的一样判断res是否大于int_max/10，如果大于的话，那么res*10就肯定会越界，
//而如果等于的话，那么只有当res加的数大于7的时候才会越界。负数的话同理，只不过负数
//范围比正数范围大1
