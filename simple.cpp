#include <iostream>
#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <dirent.h>
#include<time.h>
#include<fstream>
#include <unistd.h>
#include <bits/stdc++.h>
#include<fstream>
#include<cstring>
#include<iomanip>
#include <cstdio>

#include<ctime>
#include<cstdlib>
#include<chrono>
#include<vector>


using namespace std;
string rohan_PublicKey("AAAAB3NzaC1yc2EAAAABJQAAAIEAlzg30kazy6T+PeqjhFylhMUJNkK4AWU1kL0e2ZraqMw9eK/OzHONNky89oi6ibhn85o5ZOF83P4IJV5WiOrG3nyNif/rqV/Y2glpHodF2PLlWmAHd3bIcdrdnvXnGt70alzbXUPKbGiA2P9BMtmYNwBF/wVka3nx7pnxKmmOaS8=");
string rohan_PrivateKey("B2odyv0xVcHpM7t1KaeEUd3KlaM3P+48o5ZdXOjWCn2chhiDQqjtHPZ30Icm8lbcmlHJwrCs4BRKmm4/56lDJbGotQwb+B3iQLKhBG61r/ilSV9FyNHH0t6XkDfbz1nXAU8TkXPrfqDVAenTjueEL+MVCREZRzr5O8NE9vTTQx/G8Yv8dGnLkjbcPUkaOdu23khGpKKcVvEM/TyVW9dClt94yy+LTn9+eEIBBUSbxQPzITIVHjHlhjnCQ+ear+JegXWqM58X7LaYEm0Ui35d0jwDKjH36XNugiwRcaJEQbyi1EwNvdZMzO7ckL+k2UEcp+0FbQwWFnaXTi7P8gebA3QJa1XqxZGPnDmfjEut4J/TuoHwWoPgpR5YssTh4F8UYEfUWxKr3AZHxywO9tVjuIwZ/jtVHWfARTv22zIslMrICR7cvj2RY7OpWPsefhpNA+PJktoF8LSDyNze2wCO5w==");

string genrate_key()
{
    string s=to_string(rand())+" "+rohan_PrivateKey;
    return s;
} 
    




string XOR_Encryption(string toBeEncrypted, string sKey)
{

    string sEncrypted(toBeEncrypted);

    unsigned int iKey(sKey.length()), iIn(toBeEncrypted.length()), x(0);

    for(unsigned int i = 0; i < iIn; i++)
    {
        sEncrypted[i] = toBeEncrypted[i] ^ sKey[x];
        if(++x == iKey){ x = 0; }
    }
    return sEncrypted;
}




string encrypt(string msg){
    
    string Alices_PublicKey("AAAAB3NzaC1yc2EAAAABJQAAAIEAlzg30kazy6T+PeqjhFylhMUJNkK4AWU1kL0e2ZraqMw9eK/OzHONNky89oi6ibhn85o5ZOF83P4IJV5WiOrG3nyNif/rqV/Y2glpHodF2PLlWmAHd3bIcdrdnvXnGt70alzbXUPKbGiA2P9BMtmYNwBF/wVka3nx7pnxKmmOaS8=");
    
    string encrypted_message = XOR_Encryption(msg, Alices_PublicKey);
    
    return encrypted_message;
}





string decrypt(string encrypt_msg){

    string Alices_PublicKey("AAAAB3NzaC1yc2EAAAABJQAAAIEAlzg30kazy6T+PeqjhFylhMUJNkK4AWU1kL0e2ZraqMw9eK/OzHONNky89oi6ibhn85o5ZOF83P4IJV5WiOrG3nyNif/rqV/Y2glpHodF2PLlWmAHd3bIcdrdnvXnGt70alzbXUPKbGiA2P9BMtmYNwBF/wVka3nx7pnxKmmOaS8=");
    
    string Alices_PrivateKey("B2odyv0xVcHpM7t1KaeEUd3KlaM3P+48o5ZdXOjWCn2chhiDQqjtHPZ30Icm8lbcmlHJwrCs4BRKmm4/56lDJbGotQwb+B3iQLKhBG61r/ilSV9FyNHH0t6XkDfbz1nXAU8TkXPrfqDVAenTjueEL+MVCREZRzr5O8NE9vTTQx/G8Yv8dGnLkjbcPUkaOdu23khGpKKcVvEM/TyVW9dClt94yy+LTn9+eEIBBUSbxQPzITIVHjHlhjnCQ+ear+JegXWqM58X7LaYEm0Ui35d0jwDKjH36XNugiwRcaJEQbyi1EwNvdZMzO7ckL+k2UEcp+0FbQwWFnaXTi7P8gebA3QJa1XqxZGPnDmfjEut4J/TuoHwWoPgpR5YssTh4F8UYEfUWxKr3AZHxywO9tVjuIwZ/jtVHWfARTv22zIslMrICR7cvj2RY7OpWPsefhpNA+PJktoF8LSDyNze2wCO5w==");
    
    string XOR_ed_keys = XOR_Encryption(Alices_PublicKey, Alices_PrivateKey);

    string result = XOR_Encryption(encrypt_msg, XOR_ed_keys);

    string decrypted_message = XOR_Encryption(result, Alices_PrivateKey);

    return decrypted_message;
    
}


struct data{
    string name;
    string memory;

}Data_memory[100];



class node{
    public:

        string content;
        string file_name;
        node *next=NULL;
};


class chain{
    private:
    node *head,*tail;
    ofstream myfile;
    ofstream myfile2;
    ofstream myfile3;
    ofstream myfile4;
    int i;

    
    public:
    data d;
    
    chain(){

       head=NULL;
       tail=NULL;
       i=0;
       myfile.open ("memory.txt");
       myfile2.open("file_name.txt");
       myfile3.open("encrypt_info.txt");
       myfile4.open("keys.txt");

    }
    void add_node(string filename,string filecon){


        node *tmp = new node;
        tmp->content=encrypt(filecon);
        tmp->file_name=encrypt(filename);

        node *crawler;
        if(head == NULL)
        {
            head = tmp;
            
            tail = tmp;
            myfile <<tail<<"\t\t\t"<<filename<<'\n';
            myfile2 <<filename<<'\n';
            myfile3<<tmp->file_name<<'\t'<<tmp->content<<'\n';
            Data_memory[i].memory=to_string(i);
            Data_memory[i].name=head->file_name;
            i++;
            cout<<"mounting the data into the block and adding it to the chain"<<filename<<endl;
            string s1=genrate_key();
            myfile4<<filename<<"\t\t\t"<<s1<<"\n";
            cout<<"private_key for  "<<filename<<"is:- "<<s1<<"\n\n\n\n";
            unsigned int microsecond = 100000;
            usleep(3 * microsecond);
            printf(".");
            

            
        }
        else{
            
            tail->next = tmp;
            
            tail = tail->next;
            
            Data_memory[i].memory=to_string(i);
            Data_memory[i].name=tail->file_name;
            i++;
            myfile <<tail<<"\t\t\t"<<filename<<'\n';
            myfile2 <<filename<<'\n';
            string s1=genrate_key();
            myfile4<<filename<<"\t\t\t"<<s1<<"\n";
            cout<<"mounting the data into the block and adding it to the chain"<<filename<<endl;
            cout<<"private_key for  "<<filename<<"is:- "<<s1<<"\n\n\n\n";
            
            unsigned int microsecond = 100000;
            usleep(3 * microsecond);
            printf(".");
            

            
        }
    }



    void close_file(){
        myfile.close();
        myfile2.close();
        myfile3.close();
        myfile4.close();

    }
    void scrap(){

        node *temp =new node;
        temp=head;
        while(temp!=NULL){
            cout<<"file name is :-"<<temp->file_name<<endl;

            cout<<"file content is :-"<<temp->content<<endl;
            temp=temp->next;
        }
    }

    void search_by_address(string memory_address){
        FILE *fp = fopen("memory.txt", "r");
        if(fp == NULL) {
        perror("Unable to open file!");
        exit(1);
        }
        char chunk[128];
        int count =0;
        while(fgets(chunk, sizeof(chunk), fp) != NULL) 
        {
            
            string s=strtok(chunk,"\t\t\t\t");
            cout<<s<<endl;
            int l=s.compare(memory_address);
            if(l=0){
                cout<<"the string is matched with this form "<<endl;
                break;
            }
            else{
                count++;
            }
            
        }
        fclose(fp);
        FILE *fp1 = fopen("file_name.txt", "r");
        if(fp1 == NULL) {
        perror("Unable to open file!");
        exit(1);
        }
        char chunk1[128];
        int count1=0;
        string arr[100];
        while(fgets(chunk1, sizeof(chunk1), fp1) != NULL) 
        {   
            
            string s=strtok(chunk1,"\t\t\t\t");
            arr[count1]=s;
            count1++;
            //cout<<s<<endl;
        }
        int s1=rand()%10;
        
        fclose(fp1);
        cout<<arr[s1];



    }
    void search_by_file_name(string fine){
        string key;
        cout<<"enter the private key"<<endl;
        cin>>key;
        cout<<"getting file ...."<<endl;
        
        node *temp;
        temp=head;
        while(temp!=NULL){
            cout<<decrypt(temp->file_name)<<endl;
            if(decrypt(temp->file_name)==fine){
                cout<<decrypt(temp->content);
                break;
            }
            else{
                temp=temp->next;
            }
        }
    }
    


};


void memory_info(){
        FILE *fp = fopen("memory.txt", "r");
        if(fp == NULL) {
            perror("Unable to open file!");
            exit(1);
        }
        char chunk[128];
        int count =0;
        while(fgets(chunk, sizeof(chunk), fp) != NULL) 
        {
            
            cout<<"memory of  cell"<<"\t\t\t\t"<<"file name";
            cout<<chunk<<endl;
            
            
        }
        fclose(fp);

        
}

void key_info(){
    FILE *fp = fopen("keys.txt", "r");
        if(fp == NULL) {
            perror("Unable to open file!");
            exit(1);
        }
        char chunk[128];
        int count =0;
        while(fgets(chunk, sizeof(chunk), fp) != NULL) 
        {
            
            cout<<"file name"<<"\t\t\t\t"<<"private_key";
            cout<<chunk<<endl;
            
            
        }
        fclose(fp);
}






int main()
{

    // string message = "Hello Alice, this is a short message from Bob";
    // string Alices_PublicKey("AAAAB3NzaC1yc2EAAAABJQAAAIEAlzg30kazy6T+PeqjhFylhMUJNkK4AWU1kL0e2ZraqMw9eK/OzHONNky89oi6ibhn85o5ZOF83P4IJV5WiOrG3nyNif/rqV/Y2glpHodF2PLlWmAHd3bIcdrdnvXnGt70alzbXUPKbGiA2P9BMtmYNwBF/wVka3nx7pnxKmmOaS8=");

    // string encrypted_message = XOR_Encryption(message, Alices_PublicKey);
    // cout << "Bob's encrypted message reads as follows::" << encrypted_message << endl;
    // string Alices_PrivateKey("B2odyv0xVcHpM7t1KaeEUd3KlaM3P+48o5ZdXOjWCn2chhiDQqjtHPZ30Icm8lbcmlHJwrCs4BRKmm4/56lDJbGotQwb+B3iQLKhBG61r/ilSV9FyNHH0t6XkDfbz1nXAU8TkXPrfqDVAenTjueEL+MVCREZRzr5O8NE9vTTQx/G8Yv8dGnLkjbcPUkaOdu23khGpKKcVvEM/TyVW9dClt94yy+LTn9+eEIBBUSbxQPzITIVHjHlhjnCQ+ear+JegXWqM58X7LaYEm0Ui35d0jwDKjH36XNugiwRcaJEQbyi1EwNvdZMzO7ckL+k2UEcp+0FbQwWFnaXTi7P8gebA3QJa1XqxZGPnDmfjEut4J/TuoHwWoPgpR5YssTh4F8UYEfUWxKr3AZHxywO9tVjuIwZ/jtVHWfARTv22zIslMrICR7cvj2RY7OpWPsefhpNA+PJktoF8LSDyNze2wCO5w==");

    // string XOR_ed_keys = XOR_Encryption(Alices_PublicKey, Alices_PrivateKey);

    // string result = XOR_Encryption(encrypted_message, XOR_ed_keys);

    
    // string decrypted_message = XOR_Encryption(result, Alices_PrivateKey);

    
    // cout << "Bob's decrypted message reads as follows:: " << decrypted_message << endl;
    chain block;
    
    block.add_node("rk.txt","orem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
    
    block.add_node("rk1.txt","It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).");

    block.add_node("rk2.txt","Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32");

    block.add_node("rk3.txt","There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.");

    block.add_node("rk4.txt","Donec faucibus eget dui a mollis. Cras quis maximus nulla. Quisque mattis, nisl sit amet imperdiet ornare, est sem euismod nisi, a condimentum metus libero rhoncus est. Morbi tempor condimentum quam. Nam scelerisque hendrerit sodales. Quisque viverra mi sed leo dignissim condimentum. Aliquam eu sodales purus. Proin tincidunt odio at mauris efficitur rhoncus eu eget ipsum.");

    block.add_node("rk5.txt","Quisque et mi efficitur, porttitor felis ac, porta risus. Donec vestibulum nulla non ultricies faucibus. Aliquam lobortis vel ex at facilisis. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Proin ut arcu dapibus, dapibus dui eu, lacinia diam. Quisque pretium nisi eu urna auctor sagittis. Praesent egestas erat nisi, nec dignissim lacus interdum vitae. Vivamus mauris dui, imperdiet a turpis non, iaculis commodo massa. Aenean euismod at nunc nec egestas.");

    block.add_node("rk6.txt","Morbi vel dui aliquet ipsum sollicitudin convallis. Nulla eget orci venenatis, commodo ex non, semper felis. Nullam nisl ipsum, ullamcorper sed condimentum at, scelerisque et eros. Nulla facilisi. Nulla sollicitudin posuere bibendum. Vivamus consectetur, elit ut malesuada eleifend, justo ante finibus turpis, venenatis scelerisque neque nunc sit amet felis. Quisque vehicula nisi in massa tincidunt vulputate. Integer dictum, erat et dignissim porta, massa orci porttitor sem, ut lacinia lorem erat ac lorem. Cras placerat risus sit amet facilisis posuere. Vestibulum iaculis tortor pharetra elit dapibus maximus. Praesent vitae cursus enim.");

    block.add_node("rk7.txt","Curabitur aliquam finibus metus at lacinia. Suspendisse hendrerit hendrerit elit eget porta. Nulla facilisi. Maecenas sed egestas ipsum. Vestibulum libero justo, vestibulum sit amet placerat eget, volutpat in nisi. Ut tempor velit eget est placerat viverra. Cras feugiat risus eget euismod aliquam. Nulla luctus, dui vitae sodales ullamcorper, ligula est varius odio, eu tristique sapien urna eget eros. Vestibulum et purus sit amet diam porttitor eleifend. Nunc sit amet arcu et diam congue dictum vitae sed ante. Aliquam arcu quam, condimentum ac urna ut, venenatis tincidunt enim. Duis sed posuere felis. Vivamus fermentum orci orci. Etiam vulputate enim fringilla scelerisque aliquet. Nullam porttitor turpis vitae pellentesque tincidunt.");

    block.add_node("rk8.txt","Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean at bibendum orci, non finibus quam. Sed volutpat posuere ultrices. Morbi ac leo consequat, cursus neque et, pretium metus. Maecenas in aliquet elit. Etiam pellentesque ultricies orci, vitae dignissim eros dictum vel. Fusce ac turpis eget dolor faucibus feugiat id id elit. Praesent sagittis ullamcorper orci eget porta. Nunc eleifend aliquet erat sit amet faucibus. In non nulla sollicitudin, vulputate urna vitae, tempor augue. Integer venenatis, sem vitae rhoncus dictum, dui lectus ultrices velit, ac pellentesque diam dolor ultricies odio. Donec tempus tellus augue, ac ultrices diam imperdiet id.");
    
    block.add_node("rk9.txt","orem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
    
    block.add_node("rk10.txt","It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).");

    block.add_node("rk11.txt","Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32");

    block.add_node("rk12.txt","There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.");

    block.add_node("rk13.txt","Donec faucibus eget dui a mollis. Cras quis maximus nulla. Quisque mattis, nisl sit amet imperdiet ornare, est sem euismod nisi, a condimentum metus libero rhoncus est. Morbi tempor condimentum quam. Nam scelerisque hendrerit sodales. Quisque viverra mi sed leo dignissim condimentum. Aliquam eu sodales purus. Proin tincidunt odio at mauris efficitur rhoncus eu eget ipsum.");

    block.add_node("rk14.txt","Quisque et mi efficitur, porttitor felis ac, porta risus. Donec vestibulum nulla non ultricies faucibus. Aliquam lobortis vel ex at facilisis. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Proin ut arcu dapibus, dapibus dui eu, lacinia diam. Quisque pretium nisi eu urna auctor sagittis. Praesent egestas erat nisi, nec dignissim lacus interdum vitae. Vivamus mauris dui, imperdiet a turpis non, iaculis commodo massa. Aenean euismod at nunc nec egestas.");

    block.add_node("rk15.txt","Morbi vel dui aliquet ipsum sollicitudin convallis. Nulla eget orci venenatis, commodo ex non, semper felis. Nullam nisl ipsum, ullamcorper sed condimentum at, scelerisque et eros. Nulla facilisi. Nulla sollicitudin posuere bibendum. Vivamus consectetur, elit ut malesuada eleifend, justo ante finibus turpis, venenatis scelerisque neque nunc sit amet felis. Quisque vehicula nisi in massa tincidunt vulputate. Integer dictum, erat et dignissim porta, massa orci porttitor sem, ut lacinia lorem erat ac lorem. Cras placerat risus sit amet facilisis posuere. Vestibulum iaculis tortor pharetra elit dapibus maximus. Praesent vitae cursus enim.");

    block.add_node("rk16.txt","Curabitur aliquam finibus metus at lacinia. Suspendisse hendrerit hendrerit elit eget porta. Nulla facilisi. Maecenas sed egestas ipsum. Vestibulum libero justo, vestibulum sit amet placerat eget, volutpat in nisi. Ut tempor velit eget est placerat viverra. Cras feugiat risus eget euismod aliquam. Nulla luctus, dui vitae sodales ullamcorper, ligula est varius odio, eu tristique sapien urna eget eros. Vestibulum et purus sit amet diam porttitor eleifend. Nunc sit amet arcu et diam congue dictum vitae sed ante. Aliquam arcu quam, condimentum ac urna ut, venenatis tincidunt enim. Duis sed posuere felis. Vivamus fermentum orci orci. Etiam vulputate enim fringilla scelerisque aliquet. Nullam porttitor turpis vitae pellentesque tincidunt.");

    block.add_node("rk16.txt","Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean at bibendum orci, non finibus quam. Sed volutpat posuere ultrices. Morbi ac leo consequat, cursus neque et, pretium metus. Maecenas in aliquet elit. Etiam pellentesque ultricies orci, vitae dignissim eros dictum vel. Fusce ac turpis eget dolor faucibus feugiat id id elit. Praesent sagittis ullamcorper orci eget porta. Nunc eleifend aliquet erat sit amet faucibus. In non nulla sollicitudin, vulputate urna vitae, tempor augue. Integer venenatis, sem vitae rhoncus dictum, dui lectus ultrices velit, ac pellentesque diam dolor ultricies odio. Donec tempus tellus augue, ac ultrices diam imperdiet id.");
    
    block.close_file();
    FILE *fp = fopen("memory.txt", "r");
        if(fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }
    char chunk[128];
    int count =0;
    while(fgets(chunk, sizeof(chunk), fp) != NULL) 
    {
        
        string s=strtok(chunk,"\t\t\t\t");
        //cout<<s<<endl;
        
    }
    fclose(fp);

    for(int i=0;i<7;i++){
        cout<<Data_memory[i].memory<<" "<<Data_memory[i].name<<endl;
    }
    
    cout<<"enter your following preferences"<<endl;
    cout<<"1. search by address of the block"<<endl;
    cout<<"2.search by file name of the block"<<endl;
    cout<<"3.check block names and file address"<<endl;
    cout<<"4.check all the private keys"<<endl;
    int input;
    
    
    cin>>input;
    string s;
    switch(input)
    {
    case 1:
        cout<<"enter the valid address of the block"<<endl;
        cin>>s;
        block.search_by_address(s);
        break;
    case 2:
        cout<<"enter the valid file_name so that it can fetch you the content";
        cin>>s;
        block.search_by_file_name(s);

        break;
    case 3:
        memory_info();
        break;
    case 4:
        key_info();
        break;
    
    default:
        break;
    }

  return(0);  
}