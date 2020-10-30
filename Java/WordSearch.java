/*** Search for a word in a 2d matrix */
class WordSearch {
    public boolean exist(char[][] board, String word) {
        

        for(int row = 0; row< board.length; row++){
            for(int column = 0; column < board[row].length; column++){
                /**return true iif char at spec index & dfs of char leads to solution. DFS because of rules - neighboring cells either vertically or horizontally**/
                if(board[row][column] == word.charAt(0) && dfs(board, row, column, 0, word))
                    return true;
            }
        }
        return false; //didn't find a match for word search
        
    }
    
    public boolean dfs(char[][] board,int row, int column, int counter, String word){
        //if found word - indicated by counter match return true
        if(counter == word.length())
            return true;
        
        
        //edge case for outside of the board or no character match
        
        if(row < 0 || row >= board.length || column < 0 || column >= board[row].length || board[row][column] != word.charAt(counter)){
            return false;
        }
        
        //need a way to track cells already visited. temp variable to store value as replace by space. will be added back after recursion
        
        char temp = board[row][column];
        
        board[row][column] = ' ';
         /** dfs the row below current char OR row above it column bound board OR column over OR column before it*/
        boolean found = dfs(board, row+1, column, counter+1, word) || dfs(board, row-1, column, counter +1, word) || dfs(board, row, column+1,counter+1, word) || dfs(board, row, column-1, counter+1, word);
        board[row][column] = temp;
        
        return found;
    }
}