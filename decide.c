int​ decide_lang(​char​* str) {
    state = 0;
    int length = strlen(str);
    for(int i = 0; i < length; ++i)
    {
        char c = str[i];
        if(state == 0)
        {
            if(c == 'a')
            {
                state = 2;
                continue;
            }
            if(c == 'b')
            {
                state = 1;
                continue;
            }
            return 0;
        }
        else if(state == 1)
        {
            if c == a:
             state2 continue
             if c== b
             state3 continue
            return 0
        }
        else 
    }
    if(state == 1 || state == 3)
    return 1
    return 0
}