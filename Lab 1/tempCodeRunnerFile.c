while(tmp1 != NULL)
    {
        printf("Degree : %d\t Coefficient : %d\t Address : %d\n",tmp1->Degree,tmp1->Coefficient,&tmp1->next);
        tmp1 = tmp1->next;
    }