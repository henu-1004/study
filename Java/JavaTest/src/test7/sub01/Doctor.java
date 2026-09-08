package test7.sub01;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Doctor {
	private String name;
	private String id;
	private String special;
	List<Patient> patients = new ArrayList<Patient>();
	
	public Doctor(String name, String id, String special) {
		super();
		this.name = name;
		this.id = id;
		this.special = special;

	}
	
	public void addPatient(Patient pp) {
		patients.add(pp);
	}

	@Override
	public String toString() {
		return "의사 : " + name + "(id :" + id + ", 전문분야 : " + special + "\n담당환자 목록:\n" + patients.stream()
																										.map(Patient::toString)
																										.collect(Collectors.joining("\n")) + ")";
	}
	

	
}
