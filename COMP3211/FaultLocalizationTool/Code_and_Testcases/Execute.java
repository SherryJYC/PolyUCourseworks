/**
 * Created by Yunkun on 2017/12/7.
 */
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
public class Execute {
    public static void main(String[] args)throws IOException {
//        int loop=0;
//        for(loop=0;loop<10;loop++){
//            int[][] array=new int[625][93];
//            FileInputStream inputStream = new FileInputStream("D://sort_bug"+loop+".txt");
//            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
//            String str = null;
//            int i=0;
//            int j;
//            while((str = bufferedReader.readLine()) != null){
//                String[] strings=str.split(" ");
//                for(j=0;j<array[0].length;j++){
//                    array[i][j]=Integer.parseInt(strings[j]);
//                }
//                array[i][array[i].length-1]=1-array[i][array[i].length-1];
//                i++;
//            }
//            inputStream.close();
//            bufferedReader.close();
//            Crosstab.crosstab(array,0.05);
//        }

        int loop=0;
        for(loop=0;loop<10;loop++) {
        int[][] array=new int[3211][129];
        FileInputStream inputStream = new FileInputStream("D://encrypt_bug"+loop+".txt");
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
        String str = null;
        int i=0;
        int j;
        while((str = bufferedReader.readLine()) != null){
            String[] strings=str.split(" ");
            for(j=0;j<array[0].length;j++){
                array[i][j]=Integer.parseInt(strings[j]);
            }
            array[i][array[i].length-1]=1-array[i][array[i].length-1];
            i++;
        }
        inputStream.close();
        bufferedReader.close();
        Crosstab.crosstab(array,0.05);
        }



//        int[][] array={
//                {1,0,0,0,1,1,0,1,1,1,1},
//                {1,1,0,1,0,0,0,0,1,0,0},
//                {1,0,1,0,0,1,1,1,1,1,1},
//                {1,1,1,1,0,0,1,1,1,0,0},
//                {1,1,1,1,0,1,1,1,1,0,0},
//                {1,0,0,0,0,0,1,1,1,1,0},
//                {1,1,0,0,0,1,1,0,1,1,0},
//                {1,1,1,1,0,0,1,1,1,0,0},
//                {0,1,0,0,0,1,0,0,1,1,0},
//                {1,0,0,0,1,0,1,1,1,1,1},
//                {0,1,1,0,0,0,0,1,1,0,0},
//                {1,1,0,1,1,0,1,0,1,1,0},
//                {1,0,1,0,0,0,1,1,1,0,0},
//                {0,1,0,1,1,0,1,0,1,1,0},
//                {1,0,1,0,1,0,1,1,1,1,1},
//                {0,1,0,1,0,0,0,1,1,0,0},
//                {1,1,1,1,0,0,1,1,1,0,0},
//                {1,0,1,0,1,1,0,1,1,1,1},
//                {1,1,1,1,0,0,1,0,1,0,0},
//                {0,0,1,1,1,1,1,0,1,1,0},
//                {1,1,0,0,0,0,1,1,0,1,1},
//                {0,0,0,1,1,0,1,1,0,0,0},
//                {0,1,1,0,0,0,1,0,0,1,0},
//                {1,1,1,0,1,0,0,0,0,1,0},
//                {1,0,0,1,1,1,0,1,1,0,1},
//                {1,1,1,0,0,1,0,0,0,1,0},
//                {1,0,0,0,0,1,1,0,1,1,0},
//                {0,1,1,1,1,0,0,1,0,0,0},
//                {0,0,1,1,1,1,0,1,0,0,0},
//                {1,0,0,0,1,1,0,0,1,1,0},
//                {1,1,0,1,0,0,0,1,0,0,1},
//                {1,0,0,1,1,1,1,0,0,1,0},
//                {1,1,0,0,0,1,0,1,0,0,0},
//                {1,0,1,1,1,0,0,1,1,0,1},
//                {0,0,0,1,1,0,1,1,1,0,0},
//                {0,0,1,0,1,0,0,0,1,0,0}
//        };

    }

}
