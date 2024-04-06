set<int,desc>s1={10,30,20,50,40,10,20};
    
    for(auto x:s1)
      cout<<x<<" ";
    cout<<endl;

   
    set<int>::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
       cout<<*it<<" ";
    cout<<endl; 