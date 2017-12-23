/**
 * Created by Yunkun on 2017/12/7.
 */
import java.lang.Math;

import static java.lang.Double.NEGATIVE_INFINITY;
import static java.lang.Double.NaN;

public class Crosstab {
    public static int[] crosstab(int[][] array, double significance){
        int testAmount=array.length;
        int lineAmount=array[0].length-1;//line amount of source code which is tested
        int[] result=new int[lineAmount];
        int i=0;
        int j=0;
        int totalSuccess=0;
        int totalFail=0;
        double[] tempCover=new double[lineAmount];
        double[] tempNotCover=new double[lineAmount];
        double[] coverSuccess=new double[lineAmount];
        double[] notCoverSuccess=new double[lineAmount];
        double[] coverFail=new double[lineAmount];
        double[] notCoverFail=new double[lineAmount];
        for(i=0;i<testAmount;i++){//preprocessing
            initTempCoverArray(tempCover);
            initTempCoverArray(tempNotCover);
            for(j=0;j<lineAmount;j++){
                if(array[i][j]==0)
                    tempNotCover[j]+=1;
                else tempCover[j]+=1;
            }
            if(array[i][lineAmount]==0){
                totalSuccess+=1;
                for(j=0;j<lineAmount;j++){
                    coverSuccess[j]+=tempCover[j];
                    notCoverSuccess[j]+=tempNotCover[j];
                }
            }
            else{
                totalFail+=1;
                for(j=0;j<lineAmount;j++){
                    coverFail[j]+=tempCover[j];
                    notCoverFail[j]+=tempNotCover[j];
                }
            }
        }
        double[] zetaValue=zetaValueCalculation(coverSuccess, notCoverSuccess, coverFail, notCoverFail, totalSuccess, totalFail);
        for(j=0;j<lineAmount;j++){
            System.out.print(zetaValue[j]+", ");
//            if(zetaValue[j]==NaN)
//                zetaValue[j]=0;
        }

        double tempZeta;
        int tempLocation;


        for(j=0;j<lineAmount;j++){
            tempZeta=NEGATIVE_INFINITY;
            tempLocation=-1;
            for(i=0;i<lineAmount;i++){
                if(zetaValue[i]>tempZeta){
                    tempZeta=zetaValue[i];
                    tempLocation=i;
                }
            }
//            zetaValue[tempLocation]=NEGATIVE_INFINITY;
            zetaValue[tempLocation]=-10000;
            result[j]=tempLocation;
        }
        System.out.println();
        for(j=0;j<lineAmount;j++)
            System.out.print(result[j]+1+", ");//print # line
        System.out.println();
        return result;
    }
    public static void initTempCoverArray(double[] array){
        int i;
        for(i=0;i<array.length;i++){
            array[i]=0;
        }
    }
    public static double[] zetaValueCalculation(double[] coverSuccess, double[] notCoverSuccess, double[] coverFail, double[] notCoverFail, int totalSuccess, int totalFail){
        int size=coverSuccess.length;
        int total=totalFail+totalSuccess;
        double[] chiSquare=new double[size];
        double[] mValue=new double[size];
        double[] phiValue=new double[size];
        double[] zetaValue=new double[size];
        int i=0;
        double ecf;
        double ecs;
        double euf;
        double eus;
        for (i=0;i<size;i++){
            ecf=Math.max((coverFail[i]+notCoverFail[i])*(coverFail[i]+coverSuccess[i])/(total),1/total);
            ecs=Math.max((coverSuccess[i]+notCoverSuccess[i])*(coverFail[i]+coverSuccess[i])/(total),1/total);
            euf=Math.max((coverFail[i]+notCoverFail[i])*(notCoverFail[i]+notCoverSuccess[i])/(total),1/total);
            eus=Math.max((coverSuccess[i]+notCoverSuccess[i])*(notCoverFail[i]+notCoverSuccess[i])/(total),1/total);
            chiSquare[i]=Math.pow((coverFail[i]-ecf),2)/ecf+Math.pow((coverSuccess[i]-ecs),2)/ecs+
                    Math.pow((notCoverFail[i]-euf),2)/euf+Math.pow((notCoverSuccess[i]-eus),2)/eus;
            mValue[i]=chiSquare[i]/total;
            if(coverSuccess[i]==0){
                coverSuccess[i]++;
            }
            if(coverFail[i]+notCoverFail[i]==0){
                notCoverFail[i]++;
            }
            phiValue[i]=coverFail[i]*(coverSuccess[i]+notCoverSuccess[i])/coverSuccess[i]/(coverFail[i]+notCoverFail[i]);
            zetaValue[i]=phiValue[i]>=1?mValue[i]:-mValue[i];
        }
        return zetaValue;
    }
}