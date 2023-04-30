class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
        {
            return num;
        }
        int nxt = 0;
        while (num)
        {
            nxt += num % 10;
            num /= 10;
        }
        return addDigits(nxt);
    }
};
