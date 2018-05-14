long switch_prob(long x, long n)
{
    long result = x;
    switch(n){
        case 61:
        case 62:
            result = 8 * x;
            break;
        case 63:
            result >>= 3;
            break;
        case 64:
            result <<= 4;
            result -= x;
            x = result;
        case 65:
            x *= x;
        default:
            result = x + 59;
    }
    return result;
}