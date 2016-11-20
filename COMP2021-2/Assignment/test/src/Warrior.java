class Warrior extends Hero{
    public Warrior(String name){
        super(name);
    }
    public void doAction(Hero other){
        int damage = Math.min(getLevel() * 5, other.getHealth());
        other.setHealth(other.getHealth() - damage);
        System.out.println(getName() + " attacks " + other.getName() + ". Does " + damage + " damage.");
    }
    public void levelUp(){
        super.levelUp();
        System.out.println(getName() + " is now a level " + getLevel() + " warrior.");
    }
    public static void main(String[] args) {
        Hero hero;
        Warrior warrior;
        Healer healer;

        hero = new Warrior("Thor");
        warrior = hero;
        warrior.doAction(hero);
    }
}

class Diabolo extends Warrior {
    Diabolo(String name) {
        super(name);
    }
}