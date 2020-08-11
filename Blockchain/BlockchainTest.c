#include "Blockchain.h"


int main(){
    Blockchain blockchain;
    initBlockchain(&blockchain);

    Block *bloco0;
  
    bloco0 = generateNextBlock(&blockchain, 233);

    if(isValidNewBlock(bloco0, blockchain.genesisBlock) == true ){
         
        printf("Bloco valido \n");
        if(addBlock(&blockchain, bloco0) == 1){
           printf("Bloco adicionado \n");
        } else { 
           printf("Bloco não adicionado\n");
        };

     }else{ 

        return false;
     };
   Block *bloco1;
  
   bloco1 = generateNextBlock(&blockchain, 43);
   addBlock(&blockchain, bloco1);

   printf("Blockchain valida? %d \n",isBlockchainValid(&blockchain));

   bloco0->data = 253;

   printf("Blockchain valida? %d \n",isBlockchainValid(&blockchain));

     
 /*
    Blockchain blockchain;
    
    initBlockchain(&blockchain);
    printf("%s\n",blockchain.genesisBlock->hash);
    printf("%lu\n",blockchain.genesisBlock->timestamp);
    
    Block *newBlock2 = generateNextBlock(&blockchain,80.0);
    addBlock(&blockchain, newBlock2);
    
    Block *newBlock3 = generateNextBlock(&blockchain,250.0);
    addBlock(&blockchain, newBlock3);
    
    printf("Block 2 is valid? %i\n",isValidNewBlock(newBlock2, blockchain.genesisBlock));
    newBlock2->data = 74.00;
    printf("Blockchain is valid? %i\n",isBlockchainValid(&blockchain));
    printf("size: %u\n",blockchain.latestBlock->index);
    return 0;

*/

}