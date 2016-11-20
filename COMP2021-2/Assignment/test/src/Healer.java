class Healer extends Hero{
    private int mana;
    public Healer(String name){
        super(name);
        mana = 100;
    }
    public void doAction(Hero other){
        if(mana >= 10){
            int h = Math.min(getLevel() * 10, 100 - other.getHealth());
            other.setHealth(other.getHealth() + h);
            mana -= 10;
            System.out.println(getName() + " heals " + other.getName() + " by " + h + " points.");
        }
    }
    public void levelUp(){
        super.levelUp();
        mana = 100;
        System.out.println(getName() + " is now a level " + getLevel() + " healer.");
    }
}