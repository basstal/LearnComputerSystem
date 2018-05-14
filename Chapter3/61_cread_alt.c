long cread_alt(long *xp)
{
    long c = (long)xp;
    return (c ? *xp : 0);
}