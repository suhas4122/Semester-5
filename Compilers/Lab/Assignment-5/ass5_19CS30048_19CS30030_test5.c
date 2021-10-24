int main()
{
    int i = 0;
    int j;
    j = 100;

    while(i<7)
    {
        i = i+2;
        j = j-1;
    }

    for(i = 0; i < 3; i++)
    {
        j = j+5;
        j = j*4+8;
    }

    i = 9;

    while(i >= 5)
    {
        if(i > j){
            i--;
            j++;
        }
        else{
            i++;
            j--;
        }
    }
    
    int k = i+j;

    return 0;
}