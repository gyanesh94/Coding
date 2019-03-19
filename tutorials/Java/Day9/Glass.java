package Day9;

// Shows restriction on both class and multiple interface
public class Glass<T extends SuperLiquidClass /*Class*/ & Liquid /*Interface*/ & SuperLiquidInterFace /*Interface*/> { // extends tell T class must extends or implements Liquid class/interface
	T liquid;
}
