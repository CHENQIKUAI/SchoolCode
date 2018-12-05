public abstract class Duck {
	FlyBehavior flyBehavior;
	QuackBehavior quackBehavior;

	public Duck() {

	}

	public abstract void display();

	public void performFly() {
		flyBehavior.fly();
	}

	public void setFlyBehavior(FlyBehavior f) {
		this.flyBehavior = f;
	}

	public void setQuackBehavior(QuackBehavior q) {
		this.quackBehavior = q;
	}

	public void performQuack() {
		quackBehavior.quack();
	}

	public void swim() {
		System.out.println("All ducks float, even decoys!");
	}
}