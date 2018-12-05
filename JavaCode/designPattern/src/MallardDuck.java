
public class MallardDuck extends Duck {

	public MallardDuck() {
		this.quackBehavior = new Quack();
		this.flyBehavior = new FlyWithWings();
	}

	@Override
	public void display() {
		// TODO Auto-generated method stub
		System.out.println("I'm a MallardDuck");
	}

}
