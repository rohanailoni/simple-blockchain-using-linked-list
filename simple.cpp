#include <iostream>


using namespace std;
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

class node{
    public:

        string content;
        string file_name;
        node *next=NULL;
};
class chain{
    private:
    node *head,*tail;
    public:
    chain(){

       head=NULL;
       tail=NULL;

    }
    void add_node(string filename,string filecon){


        node *tmp = new node;
        tmp->content=encrypt(filecon);
        tmp->file_name=encrypt(filename);


        if(head == NULL)
        {
            head = tmp;
            
            tail = tmp;
        }
        else{
            
            tail->next = tmp;
            
            tail = tail->next;
        }
    }
    void scrap(){
        node *temp =new node;
        temp=head;
        while(temp!=NULL){
            cout<<"file name is :-"<<decrypt(temp->file_name)<<endl;
            cout<<"file content is :-"<<decrypt(temp->content)<<endl;
            temp=temp->next;
        }
    }


};











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
    
    block.add_node("rk.txt","my name is rohan");
    
    block.add_node("rk1.txt","your name is rohan");
    
    block.scrap();
    return 0;   
}