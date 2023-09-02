import java.util.;
import java.io.;
public
class Main
{
public
    static int digitalFoldingHash(String key, inttableSize)
    {
        int hashValue = 0;
        String digits = convertToDigits(key);
        int chunkSize = (int)Math.ceil((double)digits.length() / tableSize);
        String[] chunks = new String[tableSize];
        int startPos = 0;
        for (int i = 0; i < tableSize; i++)
        {
            if (startPos + chunkSize <= digits.length())
            {
                chunks[i] = digits.substring(startPos, startPos + chunkSize);
            }
            else
            {
            }
            for (String chunk : chunks)
            {
                int chunkValue = Integer.parseInt(chunk);
                hashValue += chunkValue;
            }
            hashValue = hashValue % tableSize;
            return hashValue;
        }
    private
        static String convertToDigits(String key)
        {
            StringBuilder digits = new StringBuilder();
            for (char ch : key.toCharArray())
            {
                digits.append((int)ch);
            }
            return digits.toString();
        }
    public
        static void main(String[] args)
        {
            Scanner scn = new Scanner(System.in);
            System.out.println("Enter the Key to be hashed");
            String key = scn.nextLine();
            System.out.println("Enter the table size");
            int tableSize = scn.nextInt();
            int hashValue = digitalFoldingHash(key, tableSize);
            System.out.println("Hash value: " + hashValue);
        }
    }