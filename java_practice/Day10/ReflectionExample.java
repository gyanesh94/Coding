package Day10;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class ReflectionExample {

	public static void main(String[] args) throws NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchFieldException {
		// Logging
		
		final String TAG = ReflectionExample.class.getName();
		System.out.println(TAG);
		System.out.println();
		
		
		// Reflection
		TestClass t = new TestClass();

		Class cls = t.getClass();

		System.out.println();
		Constructor[] conAll = cls.getConstructors();
		for(Constructor c: conAll) {
			System.out.println(c.getName());
		}
		
		Constructor cons = cls.getConstructor();
		System.out.println(cons.getName());
		t = (TestClass) cons.newInstance();
		t.methodOne();

		System.out.println();
		Method[] me = cls.getDeclaredMethods();
		for (Method m : me) {
			System.out.println(m + "\t" + m.getName());
		}

		Method m = cls.getDeclaredMethod("methodOne");
		m.invoke(t);

		Method m2 = cls.getDeclaredMethod("methodTwo", int.class);
		m2.invoke(t, 10);

		// For private method
		Method m3 = cls.getDeclaredMethod("methodThree");
		m3.setAccessible(true);
		m3.invoke(t);

		System.out.println();
		Field[] f = cls.getDeclaredFields();
		for (Field ft : f) {
			System.out.println(ft + "\t" + ft.getName());
		}

		Field f1 = cls.getDeclaredField("a");
		f1.set(t, 34);
		m.invoke(t);

		Field f2 = cls.getDeclaredField("s");
		f2.setAccessible(true);
		f2.set(t, "Private");
		m3.invoke(t);

	}

}
