import React from 'react';
import { StyleSheet, Text, View, TouchableOpacity, Alert, Button} from "react-native";

const inputView = ({ onPress, title }) => (
  <TouchableOpacity
    activeOpacity={0.8}
    onPress={onPress}
    style={styles.inputView}
  >
    <Text style={styles.appButtonText}>{title}</Text>
  </TouchableOpacity>
);

const AddButton = ({ onPress, title }) => (
  <TouchableOpacity
    activeOpacity={0.8}
    onPress={onPress}
    style={styles.addButton}
  >
    <Text style={styles.appButtonText}>{title}</Text>
  </TouchableOpacity>
);

export default function App() {
  return (
    <View style={styles.container}>
        <Text style={styles.title}>TODO LIST</Text>
      <View style={styles.bottom}>
        {/* <inputView title="Write a task" />
      </View>
      <View> */}
        <AddButton title="+" />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#00607F',
  },
  title: {
    color: '#fff',
    fontSize: 32,
    fontWeight: '600',
    marginTop: '16%',
    marginBottom: '16%',
    marginLeft: '8%',
  },
  bottom: {
    backgroundColor: '#fff',
    padding: '4%',
    marginTop: '120%',
    marginBottom: '8%',
    marginLeft: '8%',
    marginRight: '8%',
  },
  addButton: {
    alignItems: 'center',
    justifyContent: 'center',
    padding: '4%',
    borderRadius: 10,
    alignSelf: 'flex-end',
    backgroundColor: 'black',
  },
  inputView: {
    alignItems: 'center',
    justifyContent: 'center',
    padding: '4%',
    borderRadius: 10,
    alignSelf: 'flex-start',
    backgroundColor: 'black',
  },
  appButtonText: {
    fontSize: 64,
    color: "#fff",
    fontWeight: "bold",
    alignSelf: "center",
    textTransform: "uppercase"
  }
});